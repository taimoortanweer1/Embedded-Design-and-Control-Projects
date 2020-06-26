using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using Microsoft.DirectX.DirectInput;
using System.Drawing.Imaging;
using AForge.Video;
using AForge.Video.DirectShow;
using AviFile;
using Microsoft.CSharp;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Diagnostics;

namespace JoystickSample
{
	public partial class frmMain : Form
	{
		
		public JoystickInterface.Joystick jst;
		public int[] AxisArr = new int[6];
		public char[] ButArr = new char[11];
        public int check = 0;
        char send = 'S';
        VideoCaptureDevice cam = null;
        FilterInfoCollection usbCam = null;
        int frame_count;
        int sec;
        Bitmap[] img = new Bitmap[100];
        MJPEGStream mpeg = null;
        MJPEGStream mpeg1 = null;
        int a = 0;

        //************************************************
        int flag = 1;
        Socket sockfd = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        int rcv;

        string input, output;
        //IPEndPoint ipep = new IPEndPoint(IPAddress.Any, 5000);
        IPEndPoint ipep = new IPEndPoint(IPAddress.Any, 8888); 
        Socket[] clients = new Socket[10];

        //*************************************************

		public frmMain()
		{
			InitializeComponent();
		}
		public void tmrUpdateStick_Tick(object sender, EventArgs e)
		{
			// get status
			jst.UpdateStatus();
			
			// update the axes positions
			foreach (Control ax in flpAxes.Controls)
			{
				if (ax is Axis)
				{
					switch (((Axis)ax).AxisId)
					{
						case 1:
							((Axis)ax).AxisPos = jst.AxisA;
							break;
						case 2:
							((Axis)ax).AxisPos = jst.AxisB;
							break;
						case 3:
							((Axis)ax).AxisPos = jst.AxisC; //X
							break;
						case 4:
							((Axis)ax).AxisPos = jst.AxisD; //Y
							break;
						case 5:
							((Axis)ax).AxisPos = jst.AxisE;
							break;
						case 6:
							((Axis)ax).AxisPos = jst.AxisF;
							break;
					}
				}
			}

			// update each button status
			foreach (Control btn in flpButtons.Controls)
			{
				if (btn is JoystickSample.Button)
				{
					((JoystickSample.Button)btn).ButtonStatus =
						jst.Buttons[((JoystickSample.Button)btn).ButtonId - 1];
				}
			}

			Current_Status();

            label1.Text = AxisArr[0].ToString();
            label2.Text = AxisArr[1].ToString();

            send = axistochar();
            transmit(send);

            send = buttochar();
            transmit(send);


		}
        public void transmit(char tosend)
        {
            byte[] data1 = new byte[40];
            data1 = Encoding.ASCII.GetBytes(tosend.ToString());
            clients[flag].Send(data1, data1.Length, SocketFlags.None);
           // richTextBox1.Text = "F";
        
        }

		public void Current_Status()
		{

			int count = 0;
		   
			AxisArr[0] = jst.AxisC;
			AxisArr[1] = jst.AxisD;

			foreach (Control btn in flpButtons.Controls)
			{
				if (btn is JoystickSample.Button)
				{
					if (jst.Buttons[((JoystickSample.Button)btn).ButtonId-1])
					{
						ButArr[count] = '1';
						count++;
					}
					else
					{
						ButArr[count] = '0';
						count++;
					}
						   
				}
			}
        }

        public char buttochar()
        {
            if (ButArr[0] == 1)
            {
                return 'A';
            }
            if (ButArr[1] == 1)
            {
                return 'Z';
            }
            if (ButArr[2] == 1)
            {
                return 'X';
            }
            if (ButArr[3] == 1)
            {
                return 'C';
            }
            if (ButArr[4] == 1)
            {
                return 'V';
            }
            return 'S';

        }

        public char axistochar( )
        {
            int X = AxisArr[0], Y = AxisArr[1];

            if( ((X > 15000) && (X < 50000)) && ((Y > 15000) && (Y < 50000))  )  //X axis  
            {
                return 'S'; // stop
            }

            if (X < 15000)  //Left  
            {
                if ((Y > 15000) && (Y < 50000))
                {
                    return 'L'; //turn left
                }
 
            }

            if (X > 50000)  //Right  
            {
                if ((Y > 15000) && (Y < 50000))
                {
                    return 'R'; 
                }

                if (Y < 15000)
                {
                    return 'N';
                }

            }

            if (Y < 15000)  //Forward
            {
                if ((X > 15000) && (X < 50000))
                {
                    return 'F'; 
                }

                if  (X < 15000)
                {
                    return 'W';
                }

            }
            
            if (Y > 50000)  //Backward  
            {
                if ((X > 15000) && (X < 50000))
                {
                    return 'B';
                }

                if (X > 50000)
                {
                    return 'E';
                }

                if (X < 15000)
                {
                    return 'S';
                }

            }

            if (X > 50000 && Y < 15000)  //Backward  
            {  
                   return 'N';
               
            }

            

            return 'S';
        }
        
        private int int32(int p)
        {
            throw new System.NotImplementedException();
        }
        private void button2_Click(object sender, EventArgs e)
        {
            Axis ax = new Axis();
            int i = 0;

            // Find all the GameControl devices that are attached.

            // check that we have at least one device.
            if (!(check == 1)) //not connected
            {
                DeviceList gameControllerList = Manager.GetDevices(DeviceClass.GameControl, EnumDevicesFlags.AttachedOnly);

                // check that we have at least one device.
                if (gameControllerList.Count > 0)
                {
                    check = 1;
                    // grab the joystick
                    jst = new JoystickInterface.Joystick(this.Handle);
                    string[] sticks = jst.FindJoysticks();

                    jst.AcquireJoystick(sticks[0]);

                    // add the axis controls to the axis container
                    for (i = 0; i < jst.AxisCount; i++)
                    {
                        ax = new Axis();
                        ax.AxisId = i + 1;
                        flpAxes.Controls.Add(ax);
                    }


                    ///////////////////////////////////////////////////
                    ax = new Axis();
                    ax.AxisId = i + 1;
                    flpAxes.Controls.Add(ax);

                    //////////////////////////////////////////////////

                    // add the button controls to the button container
                    for (i = 0; i < 11; i++)
                    {
                        JoystickSample.Button btn = new Button();
                        btn.ButtonId = i + 1;
                        btn.ButtonStatus = jst.Buttons[i];
                        flpButtons.Controls.Add(btn);
                    }

                    // start updating positions
                    tmrUpdateStick.Enabled = true;
                    MessageBox.Show("Joystick Connected");
                }

                else
                {
                    check = 0;
                    MessageBox.Show("No Joystick detected");
                }
            }
            else
            {
                check = 1;
                MessageBox.Show("Joystick already connected");
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            byte[] data = new byte[40];          
            sockfd.Bind(ipep);
            sockfd.Listen(1);
            Thread waiting = new Thread(new ThreadStart(waitingforclient));
            waiting.Start();    
        }

        private void button3_Click(object sender, EventArgs e)
        {
            byte[] data1 = new byte[40];
            input = richTextBox1.Text;
            data1 = Encoding.ASCII.GetBytes(input);
            clients[flag].Send(data1, data1.Length, SocketFlags.None);
            richTextBox1.Text = "";
        }

        void waitingforclient()
        {
            int count = 0;
            byte[] data = new byte[40];
            label7.Text = "Waiting for Client";

            while (true)
            {
                count = count + 1;
                clients[count] = sockfd.Accept();

                label1.Text = "Connected";
                input = "A";
                data = Encoding.ASCII.GetBytes("*Welcome to my test server*");
                clients[count].Send(data, data.Length, SocketFlags.None);

                if (count == 1)
                {
                    Thread receiver1 = new Thread(new ThreadStart(myreceive1));
                    receiver1.Start();
                }

            }
        }

        void myreceive1()////////////////////////////////////////
        {
            byte[] data = new byte[40];
            while (true)
            {

                data = new byte[40];
                rcv = clients[1].Receive(data, data.Length, SocketFlags.None);
                output = Encoding.ASCII.GetString(data);
                richTextBox2.Text = "";
                if (output[1] == '2')
                {
                    richTextBox2.Text = "";
                    richTextBox2.Text = "client2: ";
                }
                richTextBox2.AppendText(output);
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            flag = 1;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            mpeg = new MJPEGStream();
            AForge.Video.DirectShow.VideoCaptureDevice fcg = new AForge.Video.DirectShow.VideoCaptureDevice();
            mpeg.Login = "admin";
            mpeg.Password = "nopass";
            mpeg.Source = "http://192.168.1.111/GetData.cgi";
            AsyncVideoSource asyncSource = new AsyncVideoSource(mpeg);
            mpeg.NewFrame += new NewFrameEventHandler(cam_NewFrame);
            mpeg.Start();
        }
        void cam_NewFrame(object sender, NewFrameEventArgs eventargs)
        {
            frame_count = frame_count + 1;
            pictureBox1.Image = (Bitmap)eventargs.Frame.Clone();
            img[a] = (Bitmap)eventargs.Frame.Clone();
            /*
                        if (a < 1)
                        {
                             aviStream = avi.AddVideoStream(true, 2, img[a]);
                             img[a].Dispose();
                        }

                        else
                        {
                            aviStream.AddFrame(img[a]);
                            img[a].Dispose();
                        }
                        a = a + 1;*/
        }
        private void button7_Click(object sender, EventArgs e)
        {
            mpeg.Stop();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            pictureBox1.Size = new System.Drawing.Size(704, 576);
        }

        private void frmMain_Load(object sender, EventArgs e)
        {

        }//////////////////


	}
}
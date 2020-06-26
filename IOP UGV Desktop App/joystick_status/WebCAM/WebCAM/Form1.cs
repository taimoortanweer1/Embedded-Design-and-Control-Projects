using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Imaging;
using AForge.Video;
using AForge.Video.DirectShow;
using AviFile;
namespace WebCAM
{
    public partial class Form1 : Form
    {
        VideoCaptureDevice cam = null;
        FilterInfoCollection usbCam = null;
        int frame_count;
        int sec;
        Bitmap [] img=new Bitmap[100];
        MJPEGStream mpeg = null;
        MJPEGStream mpeg1 = null;
        int a=0;
       // AviManager avi = new AviManager(@"C:\Users\Administrator\Desktop\2.avi", true);
       // VideoStream aviStream = null;
        public Form1()
        {
            InitializeComponent();
            button1.Text = "stop";
            button2.Text = "start";
            label1.Text = "frames";
            button3.Text = "Save Image";
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
        

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
          
            mpeg = new MJPEGStream();
            AForge.Video.DirectShow.VideoCaptureDevice fcg = new AForge.Video.DirectShow.VideoCaptureDevice();
            mpeg.Login = "admin";
            mpeg.Password = "nopass";
            mpeg.Source = "http://192.168.1.111/GetData.cgi";
            AsyncVideoSource asyncSource = new AsyncVideoSource(mpeg);           
            mpeg.NewFrame += new NewFrameEventHandler(cam_NewFrame);
            mpeg.Start();
           
            Timer ti = new Timer();
            /* sec = 0;          
            
            frame_count = 0;
            //usbCam = new FilterInfoCollection(FilterCategory.VideoInputDevice);
            //cam = new VideoCaptureDevice(usbCam[0].MonikerString);
            VideoCaptureDeviceForm Video_Input = new VideoCaptureDeviceForm();
            Video_Input.ShowDialog();
            cam =new VideoCaptureDevice(Video_Input.VideoDeviceMoniker);
            cam.NewFrame +=new  NewFrameEventHandler(cam_NewFrame);
            cam.Start();*/
            
           
            ti.Interval = 1000;
            ti.Tick += new EventHandler(time);
            ti.Start();
        }

        private void button1_Click(object sender, EventArgs e)
        {
           // cam.Stop();
            mpeg.Stop();
          //  avi.Close();
           
        }

        private void timer1_Tick(object sender, EventArgs e)
        {

        }
        void time(object sender,EventArgs e)
        {
            sec = sec + 1;
            label1.Text = (frame_count / sec).ToString();
            frame_count = 0;
            sec = 0;
          
        
            }


        private void button3_Click(object sender, EventArgs e)
        {
           
            
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            pictureBox1.Size =  new System.Drawing.Size(704,576);
        }

       
    }
}

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp> // for camera
using namespace cv;

int main()
{
    VideoCapture Lcap;
    VideoCapture Rcap;
    Lcap.open(1);//白色摄像头
	Lcap.set(CV_CAP_PROP_FOURCC ,CV_FOURCC('M', 'J', 'P', 'G') );
 	Lcap.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
	Lcap.set(CV_CAP_PROP_FRAME_HEIGHT,720);
    Rcap.open(2);//黑色摄像头
	 Rcap.set(CV_CAP_PROP_FOURCC ,CV_FOURCC('M', 'J', 'P', 'G') );
	 Rcap.set(CV_CAP_PROP_FRAME_WIDTH, 1280);
	 Rcap.set(CV_CAP_PROP_FRAME_HEIGHT,720);
    if (!Lcap.isOpened()||!Rcap.isOpened())
    {
        return -1;
    }
    namedWindow("Video1", 1);
    namedWindow("Video2", 2);
    while (1)
    {
        Mat frame;
        Lcap >> frame;
        imshow("Video1", frame);
        waitKey(1);//用cv::waitKey来更新界面
        Rcap >> frame;
        imshow("Video2", frame);
        waitKey(1);
    }
    Lcap.release();
    Rcap.release();
    return 0;
}

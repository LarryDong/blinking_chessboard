
// This demo convert a bipolar event frame to a 'standard' chessboard


#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>

#include <opencv2/highgui/highgui.hpp>

#include <gflags/gflags.h>


using namespace cv;


DEFINE_string(save_path, "/home/larrydong/output", "saving path");


void toMonoColor(Mat& img){
    uchar *data = img.data;
    for (int i = 0; i < img.cols; ++i){
        for (int j = 0; j < img.rows; ++j){
            int idx = j * img.cols + i;
            uchar v = data[idx];
            // convert: non-active-> white background; blinking blocks-> black chessboard
            data[idx] = (v == 0 || v == 255) ? 0 : 255;     
        }
    }
    imshow("mono", img);
}



void imageCallback(const sensor_msgs::ImageConstPtr &msg){
    cv_bridge::CvImagePtr cv_ptr = cv_bridge::toCvCopy(msg, "mono8");
    Mat img = cv_ptr->image;
    imshow("src", img);
    int c = waitKey(10);
    if (c == 's'){
        double ts = msg->header.stamp.toSec();
        string filename = FLAGS_save_path + "/" + to_string(ts) + ".bmp";
        toMonoColor(img);
        imwrite(filename, img);
        
        ROS_INFO_STREAM("Image saved to: " << filename);
    }
    else if (c == 'q')
        std::exit(0);
}


int main(int argc, char **argv) {

    ROS_INFO("Image receiver");
    ros::init(argc, argv, "receiver");
    ros::NodeHandle nh;
    google::ParseCommandLineFlags(&argc, &argv, true);

    image_transport::ImageTransport it(nh);
    image_transport::Subscriber subImage = it.subscribe("/event_frame", 10, imageCallback);

    ros::Rate r(20);
    while (ros::ok()) {
        ros::spinOnce();
        r.sleep();
    }
    return 0;
}


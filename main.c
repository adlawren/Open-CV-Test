/*
  Written using the following for reference: http://stackoverflow.com/questions/14833553/reading-a-video-with-opencv/14838999#14838999
*/

#include <cv.h>
#include <highgui.h>

#include <iostream>

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr << "Please provide a single file name" << std::endl;
    return -1;
  }

  cv::VideoCapture cap(argv[1]);
  if (!cap.isOpened())
  {
    std::cerr << "Failed to open file" << std::endl;
    return -1;
  }

  cv::Mat frame;
  for (;;)
  {
    if (!cap.read(frame))
    {
      break;
    }

    cv::imshow("window", frame);

    char key = cvWaitKey(10);
    if (key == 27)
    {
      break;
    }
  }
  
  return 0;
}

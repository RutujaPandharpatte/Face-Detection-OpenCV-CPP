#include<iostream>

#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;

CascadeClassifier faceDetection;
String str, op;

void livedetect()
{
	VideoCapture cap(0);
	if (!cap.isOpened())
	{
		cout << "\nCamera is NOT Accessible\n";
		exit(0);
	}
	system("cls");
	cout << "Enter file name by which you want to store the Image with Detected Face/s : ";
	cin >> str;
	op = "D:\\College\\KIT\\Projects\\2nd Year\\4th Sem\\Mini Project\\Output\\Live Video\\" + str + ".jpg";
	while (1)
	{
		system("cls");
		Mat frame;
		cap >> frame;
		vector<Rect> fc;
		faceDetection.detectMultiScale(frame, fc, 1.1, 5, 0, Size(40, 40));
		int i = 0;
		for (i = 0; i < fc.size(); i++)
		{
			Point p1(fc[i].x, fc[i].y);
			Point p2((fc[i].x + fc[i].width), (fc[i].y + fc[i].height));
			rectangle(frame, p1, p2, Scalar(0, 0, 255), 2, 8, 0);
		}
		imshow("LIVE", frame);
		if (i != 0)
		{
			imwrite(op, frame);
			char c = (char)waitKey(10);
			if (c == 27 || c == 'q' || c == 'Q')
			{
				exit(0);
			}
		}
	}
}

void imgdetect()
{
	char path[] = "D:\\College\\KIT\\Projects\\2nd Year\\4th Sem\\Mini Project\\Image\\tc.jpg";
	Mat img = imread(path, IMREAD_UNCHANGED);
	if (img.empty())
	{
		cout << "\nImage is not loaded\n";
		exit(0);
	}
	else
	{
		cout << "\nImage is found\nProcessing......\n";
		vector<Rect> fc;
		faceDetection.detectMultiScale(img, fc);
		int i = 0;
		for (i = 0; i < fc.size(); i++)
		{
			Point p1(fc[i].x, fc[i].y);
			Point p2((fc[i].x + fc[i].width), (fc[i].y + fc[i].height));
			rectangle(img, p1, p2, Scalar(0, 0, 255), 2, 8, 0);
		}
		if (i != 0)
		{
			system("cls");
			cout << "Enter file name by which you want to store the Image with Detected Face/s : ";
			cin >> str;
			op = "D:\\College\\KIT\\Projects\\2nd Year\\4th Sem\\Mini Project\\Output\\Image\\" + str + ".jpg";
			while (1)
			{
				system("cls");
				imwrite(op, img);
				imshow("FACE DETECTED", img);
				char c = (char)waitKey(10);
				if (c == 27 || c == 'q' || c == 'Q')
				{
					exit(0);
				}
			}
		}
		else
		{
			cout << "Face/s are Not PRESENT";
			exit(0);
		}
	}
}

int main()
{
	int ch;
	if (!faceDetection.load("C:\\OpenCV\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt.xml"))
	{
		cout << "\nFile is not Loaded\n";
		exit(0);
	}
	cout << "\n************************************************************************************************************************";
	cout << "\n************************************************************************************************************************";
	cout << "\n***                                                                                                                  ***";
	cout << "\n***                                         Welcome to Face Detection system                                         ***";
	cout << "\n***                                                                                                                  ***";
	cout << "\n************************************************************************************************************************";
	cout << "\n************************************************************************************************************************";
	cout << "\n\n                                          ";
	system("pause");
	system("cls");
	cout << "\n\n\n\tWhat you want to do?\n";
	cout << "\t1. Live Face Detection\n\t2. Image Face Detection\n\t3. Exit\n\tPlease Enter Your Choice : ";
	cin >> ch;
	if (ch == 1)
	{
		livedetect();
	}
	else if (ch == 2)
	{
		imgdetect();
	}
	else if (ch == 3)
	{
		exit(0);
	}
	else
	{
		cout << "\nInvalid Choice\nExiting\n";
		exit(0);
	}
	return 0;
}
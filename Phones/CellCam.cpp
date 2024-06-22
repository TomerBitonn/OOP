#include "CellCam.h"

CellCam::CellCam()
{
	photoSize = 0;
	Photos = new int(sizeof(int));
}

void CellCam::takePhotos()
{
	cout << endl << "Enter the number of photos you want to take: ";
	cin >> photoSize;
	Photos = new int[photoSize];
	for (int i = 0, j = 1; i < photoSize; i++, j++)
	{
		cout << "Taking photo " << j << " - Smile: ";
		cin >> Photos[i];
	}
}

void CellCam::showPhotos() const
{
	cout << endl << "Printing photos list:" << endl;
	for (int i = 0, j = 1; i < photoSize; i++, j++)
	{
		cout << "Photo " << j << ": " << Photos[i] << endl;
	}
}

int CellCam::getPhotos() const
{
	return photoSize;
}
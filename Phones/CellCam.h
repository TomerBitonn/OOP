#include "CellNoCam.h"

#pragma once
class CellCam : public CellNoCam
{
private:
	int *Photos;
	int photoSize;
public:
	CellCam();
	~CellCam() { delete Photos; }
	void takePhotos();
	void showPhotos() const;
	int getPhotos() const;
};
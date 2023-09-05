#include <bits/stdc++.h>
#include "png.h"
#include "pixel.h"
#include <png.h>

using namespace tinypng;

int main()
{
    PNG myPng("test_in.png");
    if(myPng.writeToFile("dogImage.png"));
}
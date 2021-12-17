# DangerousObjectsDetector
# HSE Project

## C++17

Libraries:
- Qt
- OpenCV
- Boost

Using Algorithms:
- Haar Cascades
- Apple MVC

###Sources are provided by GPLv2
###Test samples are under BSD license

####How to use?
To Train models, you should add yours images to path train with one pattern B???_001?. Then you should execute python3 class.py, that will create dat files, containing information about dataset of images of owr object and dataset with all others images, which are not an owr object. Then you have to change cascade.sh adding lines changing "B????" to your pattern, also you have to change train_haar. After that launch ./cascade.sh and ./train_haar. Now you have to open generated dirs, which contains cascade.xml, you have to move them to application directory and change name as you wish(it will show in app like you named it). After that application path should contain image with name "1.jpg"(yeah, i know this is bug, but didn't have time to fix it). And now you can open your application.

cd app-path
./DangerousObjectSearcher

Now you can touch image and choose any image, what you want and see result(if it exists).

####Known issues
- Bad detection due to algorithm specifics
- "1.jpg" bug

#####Made by Dim434(ddif).
# native_b

Aims to identify marked words with phone camera in real time

## Detail
Upgrade version of repo [BeatCET6](https://github.com/kyshel/BeatCET6), final target is to detect marked words in REAL TIME, aims to boost words look-up.
Syncing by vcs-github integrated in as2.4x64, as a compromise that my phone did not response to INSTANT RUN in as2.3 stable version.

## Require
- change Line8 in CMakeLists.txt
- import OpenCV3.2 module from `OpenCV-android-sdk\sdk\java`
- move dir `OpenCV-android-sdk\sdk\native\libs` to `app\src` and rename `libs` to `jniLibs`

## License
BSD

## Develop Progress
- 170404: idea appear
- 170405: visual studio opencv setup,with opencv3.2; explore andoid studio, with first app
- 170406: android studio opencv setup, with opencv 3.2; learn NDK, config official sample one by one
- 170407: native finish; all official sample passed, except camera calibration; get exception from dead process
- 170408: get mat from frame , but rgba method get wrong color
- 170409: save image from camera frame, convert right color in native method; manipulating vs2017 focusing on c++
- 170410: testing opencv samples

## Wait
core module [dig-word](https://github.com/kyshel/dig-word) need

## Predict
- One more week need
- OCR will be slow


# Blinking Chessboard

Generate blinking chessboard video for event-based camera calibration.


## Environment
`opencv-python` is needed.  


## Usage
```bash
python genearte_video.py
    --pattern ../pattern/chessboard.png
    --frequency 10
    --duration 5
    --name output_video.avi
    --encoder MJPG
```
`pattern`: the chessboard picture path. Default: a 9x6 pattern  
`frequency`: blinking frequency (Hz). Default: 10  
`duration`: video duration in second (s). Default: 10  
`name`: output video name. End in 'avi/mp4' and so on. Defualt: output.avi  
`encoder`: video encoder, may be 'MJPG/XVID' and so on. Default: MJPG  

Then play the video on a screen in front of the camera.


## Utilities
`convert_frames.cpp`

This demo convert a `bipolar` event-frame into a monocular one.

The event-frame may have 3 values: 0/255 for negative/positive events, and 128 for non-active pixels,  
but the ideal "chessboard" is black on white background.  
So this demo does this job.

![convert_result](/pictures/output.bmp)


## Reminder
- Make sure the blinking time is shorter than the duration of your "event-frame slice". The event-frame duration could be as large as possible.
- A high refreshing-rate monitor is recommended. Otherwise, your monitor may not show the changes of blinking chessboard ideally.
- Make sure your monitor do not reflect lights(or shadows) in the environment, otherwise the chessboard may be not complete.

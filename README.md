
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


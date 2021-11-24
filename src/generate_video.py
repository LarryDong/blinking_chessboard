#!/usr/bin/env python

import argparse
import cv2
import numpy as np



if __name__ == "__main__":

    parser = argparse.ArgumentParser(description="generate camera-calibration pattern", add_help=False)
    parser.add_argument("--pattern", help="pattern file", default="../pattern/chessboard_9x6.png")
    parser.add_argument("--frequency", help="blinking frequency", default=10, type=int)
    parser.add_argument("--duration", help="video duration in second", default=10, type=int)
    parser.add_argument("--output", help="output video name", default='output.avi')
    parser.add_argument("--encoder", help="video encoder", default='MJPG')

    args = parser.parse_args()

    print('Generate video using image from: ', args.pattern)
    img_pattern = cv2.imread(args.pattern, 0)                               # read gray image
    img_background = np.ones(img_pattern.shape, dtype=np.uint8) * 255       # create white background

    if img_pattern is None:
        print('Cannot load pattern from: ', args.pattern)

    # create frames
    frames = []
    for _ in range(int(args.duration * args.frequency)):
        frames.append(img_pattern)
        frames.append(img_background)

    # generate video
    fourcc = cv2.VideoWriter_fourcc(*args.encoder)
    fps = args.frequency*2
    size = (img_pattern.shape[1], img_pattern.shape[0])
    writer = cv2.VideoWriter(args.output, fourcc, fps, size, False)
    for frame in frames:
        writer.write(frame)
    writer.release
    print('Video saved.')

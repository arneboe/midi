#!/bin/sh

(
echo "reset halt"
sleep 1
echo "flash write_image erase /home/arne/git/midi/Release/midi.hex"
sleep 2
echo "reset run"
sleep 1
echo "exit"
) | telnet localhost 4444

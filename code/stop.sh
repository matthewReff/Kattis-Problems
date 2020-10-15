#!/bin/bash
stopString="//Stop: "
stopString=${stopString}$(date)
echo $stopString >> $1.cpp
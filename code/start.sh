#!/bin/bash
startString="//Start: "
startString=${startString}$(date)
echo $startString >> $1.cpp
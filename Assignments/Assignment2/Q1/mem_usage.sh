#!/bin/bash

#read -p "Please enter the PID of the process: "  PID

echo "PID of the process : $1"
PID="$1"

echo -n "Total program size : " 
awk '{ print $1 } ' /proc/$PID/statm

echo -n "Resident set size :"
awk '{ print $2 } ' /proc/$PID/statm

echo -n "Number of resident shared pages :"
awk '{ print $3 }' /proc/$PID/statm

echo -n "Size of Text(code) segment :"
awk '{ print $4 }' /proc/$PID/statm

echo -n "Size of Library code (unused since Linux 2.6. Always 0) :"
awk '{ print $5 }' /proc/$PID/statm

echo -n "Size ofData (data segment + stack) :"
awk '{ print $6 }' /proc/$PID/statm

echo -n "Dirty pages (unused since Linux 2.6. Always 0) :"
awk '{ print $7 }' /proc/$PID/statm


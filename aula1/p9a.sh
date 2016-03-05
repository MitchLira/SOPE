#!/bin/bash

name=$1

nameo=$name".o"
namec=$name".c"

rm -rf $nameo

gcc -Wall -o  $name $namec > /dev/null 2>&1

if [ $? != 0 ]; then
        echo "COMPILATION ERROR"
else
    ./$name
fi



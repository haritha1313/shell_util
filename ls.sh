#!/bin/bash
 for file in `ls /home/pegasus/Documents`
    do
    echo "$file"
    arrayy+=("$file")
    done

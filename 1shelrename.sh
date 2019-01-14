#!/bin/bash
p=0
for i in *.jpg;
do
  mv "$i" "d$p.jpg"
  ((p++))
done

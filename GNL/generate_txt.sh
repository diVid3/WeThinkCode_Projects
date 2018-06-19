#!/bin/bash

# Generates text files for GNL.

CNTR=0

while [ $CNTR -lt 5000 ]
do
	echo 123456789 >> ./gnltext.txt
	CNTR=$((CNTR + 1))
done

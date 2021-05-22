#!/bin/bash
set -x

rm output.txt

Samples_folder="."
for one_sample in ${Samples_folder}/*.cact; do
    echo "Compiling ${one_sample}"
    ../build/compiler ${one_sample}
    echo $? $'\t' ${one_sample} >> output.txt
done
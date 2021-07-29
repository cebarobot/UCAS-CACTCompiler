#!/bin/bash
set -x

rm output.txt

Samples_folder="."
for one_sample in ${Samples_folder}/*.cact; do
    echo "Compiling ${one_sample}"
    ../build/compiler ${one_sample} ../out/${one_sample/cact/s}
    riscv64-unknown-elf-gcc ../out/${one_sample/cact/s} -o ../out/${one_sample/cact/o} -L ../libcact -lcact
    echo $? $'\t' ${one_sample} >> output.txt
done
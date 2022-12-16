#!/bin/bash

cd simulator

# Python codegen
cd codegen
sim_setup_path=$1
python codegen.py -f ../../${sim_setup_path}
cd ..

# Compile
make clean
make

# launch the simulation
./bin/run.x

cd ..

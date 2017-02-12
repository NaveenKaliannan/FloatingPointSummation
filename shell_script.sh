make clean
make
./main output/data/AbsoluteErrorData.dat output/data/TimeData.dat
make -C output/gnuplot

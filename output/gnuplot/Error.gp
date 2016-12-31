set terminal png enhanced
set terminal postscript enhanced
set terminal postscript eps enhanced
set term postscript enhanced color
set output "colorindex.ps"
set key box lw 3
set key height 1
set key left
set border lw 4
set grid
set lmargin at screen 0.19
set style line 1 lt 0 lc rgb "red" lw 3
set style line 2 lt 2 lw 3
set style line 3 lt 3 lw 3
plot "../data/AbsoluteErrorData.dat" using 1:2  title "Normal summation" with linespoints ls 1 pt 1 ps 2 , "../data/AbsoluteErrorData.dat" using 1:3  title "Kahan summation" with linespoints ls 2 pt 3 ps 2, "../data/AbsoluteErrorData.dat" using 1:4  title "Pairwise summation (N = 100.)" with linespoints ls 3 pt 2 ps 2, "../data/AbsoluteErrorData.dat" using 1:5  title "Pairwise summation (N = 1000)" with linespoints ls 6 pt 4 ps 2 
set title "Error Comparison" font "arial,24"
set xtic font "arial,15"
set xlabel "N sums"  font "arial,18"
set ylabel "Absolute Error" font "arial,18"
set logscale x
set xrange [1:2000000000]
set yrange [1e-17:1e-3]
set format y "%2.e"
set ytics ("-1e-14" 1e-17,"0" 1e-16,"1e-14" 1e-14,"1e-12" 1e-12,"1e-10" 1e-10,"1e-08" 1e-08,"1e-06" 1e-06,"1e-04" 1e-04)  font "arial,15"
set logscale y
set terminal png font arial 20 size 1024,768
set output "../graph/Error.png"
replot


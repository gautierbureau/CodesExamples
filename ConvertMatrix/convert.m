load('data.dat');
load('val.dat');
load('indices.dat');
load('ind.dat');
load('indptr.dat');
load('ptr.dat');

mat = mmread('fidap001.mtx');

load('result.mat');

diff = mat - csc_mat;
import scipy.io as scio
import scipy.sparse as sp
import numpy as np

mat = scio.mmread("fidap001.mtx")
csc_mat = sp.csc_matrix(mat)

np.savetxt("data.dat", csc_mat.data)
np.savetxt("indices.dat", csc_mat.indices)
np.savetxt("indptr.dat", csc_mat.indptr)

a={}
a['csc_mat']=csc_mat
scio.savemat("result", a)
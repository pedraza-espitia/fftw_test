from matplotlib import pyplot as plt
import numpy as np

x_ = np.loadtxt('data.dat')
#x_ = np.array( [0., 0.707, 1., 0.707, 0., -0.707, -1., -0.707] )

N = len( x_ )
X_ = np.zeros( (N,2) )
for k in np.arange( N ): # frequency bins ( Fourier coefficients )
	real = 0. ;	cmplx = 0.
	for n in range ( N ):
		bn = -2*np.pi * k * n/N
		real += x_[n] * np.cos( bn )
		cmplx += x_[n] * np.sin( bn )
	X_[k,0] = real
	X_[k,1] = cmplx

magnitud = np.sqrt( X_[:,0]**2 +X_[:,1]**2 )
fig = plt.figure(1)
ax = fig.add_subplot(111)
ax.set_xlabel(r'freq')
ax.set_ylabel(r'$\alpha$*ampl')
ax.plot(magnitud)
plt.show()
#print( X_ )
# numpy.savetxt(pathFile+'salida.dat', mydata[0:1000], \
# 		delimiter='', fmt='%3.5f')
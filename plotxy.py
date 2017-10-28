from matplotlib import pyplot as plt
import numpy as np

def main():
	file = 'salida.fftw'
	x,y = np.loadtxt(file, delimiter=',', usecols=(0,1), unpack = True)

	magnitud = np.sqrt(x**2 + y**2)
	fig = plt.figure(1)
	ax = fig.add_subplot(111)
	ax.set_xlabel(r'$x$')
	ax.set_ylabel(r'$y$')
	ax.plot(magnitud)
	#ax.set_title(r'Componente '+variable+', layer Z='+str('%02d' % m))

	#plt.savefig( path+'Componente'+variable+str('%02d' % m)+'.png' , bbox_inches = 'tight' ,\
	#  transparent = 0 )
	#plt.close(m)

	plt.show()

if __name__ == '__main__':
    main()

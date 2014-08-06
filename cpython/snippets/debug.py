'''
Created on Feb 5, 2013

@author: ajaniv

'''


def set_trace():
    import sys
    from IPython.core.debugger import Pdb
    Pdb(color_scheme='Linux').set_trace(sys._getframe().f_back)

def debug( f, *args, ** kwargs): 
    from IPython.core.debugger import Pdb 
    pdb = Pdb( color_scheme='Linux') 
    return pdb.runcall(f, *args, **kwargs)


 
def check_trace():
    """
    """
    print ('checking')
    set_trace()
    print ('checked')

if __name__ == '__main__':
    check_trace()
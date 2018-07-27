import numpy
from numpy.distutils.core import setup, Extension

module = Extension('rnoise',
                    define_macros = [('MAJOR_VERSION', '1'),
                                     ('MINOR_VERSION', '0')],
                    include_dirs = [numpy.get_include(), 'python/',
                                    'lib/', 'dependencies/eigen/'],
                    language = "c++",
                    libraries = [],
                    library_dirs = [],
                    extra_compile_args=['-std=c++14',
                                        '-fopenmp',
                                        '-O3',
                                        # '-g',
                                        '-Wno-write-strings'],
                    extra_link_args=[ '-fopenmp' ],
                    sources = [
                        'python/rnoise.cpp',
                        'lib/perlin.cpp',
                    ])

setup (name = 'RNOISE',
       version = '1.0',
       description = 'Functions related to noise generation',
       author = 'Remi Lespinet',
       author_email = 'remi@lespi.net',
       url = '',
       long_description = '''
Functions related to noise generation
''',
       ext_modules = [module])

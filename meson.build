project('my_project', 'cpp')

libsimple_proj = subproject('trilka')
libsimple_dep = libsimple_proj.get_variable('libsimple_dep')

subproject('sandbox')

executable('my_project',
  'my_project.cpp',
  dependencies : libsimple_dep,
  install : true)

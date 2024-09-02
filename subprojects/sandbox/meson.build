project('sandbox', 'cpp')

add_project_arguments('-DTK_PLATFORM_MACOS', language: 'cpp')

cc = meson.get_compiler('cpp')
libtrilka = cc.find_library('trilka',  dirs : [join_paths(meson.current_source_dir(), '../trilka/build')])

inc = include_directories('../trilka')

executable('sandbox',
  'Sandbox.cpp',
  dependencies : libtrilka,
  install : true,
  include_directories : inc,
)

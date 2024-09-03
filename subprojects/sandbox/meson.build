project('sandbox', 'cpp', 
  version : '0.1',
  default_options : ['cpp_std=c++11'],
)

add_project_arguments('-DTK_PLATFORM_MACOS', language: 'cpp')

cc = meson.get_compiler('cpp')
libtrilka = cc.find_library('trilka',  dirs : [join_paths(meson.current_source_dir(), '../trilka/build')])

inc = include_directories('../trilka', '../trilka/vendor/spdlog/include')

executable('sandbox',
  'Sandbox.cpp',
  dependencies : libtrilka,
  install : true,
  include_directories : inc,
)

project('trilka', 'cpp',
      version : '0.1',
      default_options : ['cpp_std=c++11'],
)

cpp_defines = ['-DTK_PLATFORM_MACOS', '-DTK_BUILD_DLL']

include_directories = include_directories('src/trilka', 'vendor/spdlog/include')
sources = files('src/trilka/Application.cpp', 'src/trilka/Log.cpp')

libtrilka = shared_library('trilka',
  include_directories : include_directories,
  sources : sources,
  install : true,
  cpp_args : cpp_defines
)

libtrilka_dep = declare_dependency(include_directories : include_directories,
  link_with : libtrilka)

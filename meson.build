enigma_deps = [
  dependency('threads', required : true),
  meson.get_compiler('c').find_library('m', required : false),
  ]

enigma_c_args = []

if host_machine.system() == 'windows'
  enigma_c_args += [
    '-DBUILDING_MY_LIBRARY',
    ]
elif host_machine.system() == 'linux'
  enigma_c_args += [
    '-fvisibility=hidden',
    ]
endif

enigma_srcs = [
  'src/e_dynarr.c',
  'src/e_thread.c',
  'src/e_logger.c',
  'src/e_matrix.c',
  'src/e_debug_mem.c',
  'src/e_path.c',
  'src/e_text.c',
  'src/e_types.c',
  'src/e_noise.c',
  'src/e_math.c',
  ]

if library_buildtype == 'shared'
  enigma_c_args += '-D_ENIGMA_INTERNAL'
  libenigma = shared_library(
    'enigma',
    sources : enigma_srcs,
    c_args : enigma_c_args,
    include_directories : include_directories('include'),
    dependencies : enigma_deps,
    install : true)
elif library_buildtype == 'static'
  libenigma = static_library(
    'enigma',
    sources : enigma_srcs,
    c_args : enigma_c_args,
    include_directories : include_directories('include'),
    dependencies : enigma_deps,
    install : true)
endif

# tests
test_e_math = executable('test_e_math',
  'test/test_e_math.c',
  sources : enigma_srcs,
  dependencies : enigma_deps,
  c_args : enigma_c_args,
  include_directories : include_directories('include'),
  install : false)

test_e_dynarr = executable('test_e_dynarr',
  'test/test_e_dynarr.c',
  sources : enigma_srcs,
  dependencies : enigma_deps,
  c_args : enigma_c_args,
  include_directories : include_directories('include'),
  install : false)

test('test_e_math', test_e_math)
test('test_e_dynarr', test_e_dynarr)

dep_libenigma = declare_dependency(
  include_directories : include_directories('include'),
  link_with : libenigma)

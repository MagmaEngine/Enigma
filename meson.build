libenigma = library(
  'enigma',
  'src/e_dynarr.c',
  'src/e_matrix_operations.c',
  'src/e_mem_debug.c',
  'src/e_path.c',
  'src/e_text.c',
  'src/e_types.c',
  'src/e_noise.c',
  'src/e_matrix_make.c',
  'src/e_math.c',
  include_directories: include_directories('include'),
  dependencies : [
    m_dep,
  ],
  install : false)

# tests
test_e_math = executable('test_e_math', 'test/test_e_math.c', dependencies : m_dep, install : false)
test('test_e_math', test_e_math)

libenigma_dep = declare_dependency(
  include_directories: include_directories('include'),
  link_with : libenigma)

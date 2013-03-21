require 'mkmf'

if have_func('mallinfo', 'malloc.h')
  create_makefile('mallinfo')
end

let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/EC/eclib
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +286 eclib/include/ec_list.h
badd +26 eclib/src/ec_list.c
badd +118 eclib/include/ec_array.h
badd +11 test/ec_array_test.c
badd +1 eclib/include/ec.h
badd +43 eclib/include/ec_object.h
badd +1 eclib/src/ec_object.c
badd +33 test/test_ec_object.c
badd +1 eclib/src/ec_array.c
badd +18 test/ec_object_test.c
badd +18 test/ec_array.c
badd +28 test/ec_list_test.c
badd +4 eclib/include/ec_vector.h
badd +1 eclib/src/ec.c
badd +1 eclib/src/ec_vector.c
badd +27 eclib/include/ec_garbage.h
badd +1 eclib/src/ec_garbage.c
badd +5 eclib/include/ec_syntax.h
badd +1 eclib/src/ec_syntax.c
badd +4 eclib/include/ec_bool.h
badd +1 eclib/src/ec_bool.c
badd +23 eclib/include/ec_class.h
badd +1 eclib/src/ec_class.c
badd +9 eclib/include/ec_string.h
badd +1 eclib/src/ec_string.c
badd +1 eclib/include/ec_error.h
badd +1 eclib/src/ec_error.c
badd +1 src/ec.c
badd +1 include/ec_class.h
badd +1 src/ec_class.c
badd +46 include/ec_object.h
badd +1 src/ec_object.c
badd +17 include/ec_array.h
badd +1 src/ec_array.c
badd +21 include/ec_list.h
badd +1 src/ec_list.c
badd +5 include/ec_garbage.h
badd +1 src/ec_garbage.c
badd +4 include/ec_vector.h
badd +1 src/ec_vector.c
badd +1 include/ec_syntax.h
badd +1 src/ec_syntax.c
badd +10 include/ec_bool.h
badd +1 src/ec_bool.c
badd +1 include/ec_string.h
badd +1 src/ec_string.c
badd +6 include/ec_error.h
badd +1 src/ec_error.c
badd +1 include/ec.h
badd +43 tools/CMakeLists.txt
badd +0 tools/setup.sh
argglobal
silent! argdel *
set stal=2
edit include/ec.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 23 - ((22 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
23
normal! 011|
lcd ~/EC/eclib/include
wincmd w
argglobal
if bufexists('~/EC/eclib/src/ec.c') | buffer ~/EC/eclib/src/ec.c | else | edit ~/EC/eclib/src/ec.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 06|
lcd ~/EC/eclib/src
wincmd w
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
tabedit ~/EC/eclib/include/ec_class.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 29 - ((28 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
29
normal! 047|
lcd ~/EC/eclib/include
wincmd w
argglobal
if bufexists('~/EC/eclib/src/ec_class.c') | buffer ~/EC/eclib/src/ec_class.c | else | edit ~/EC/eclib/src/ec_class.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/EC/eclib/src
wincmd w
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
tabedit ~/EC/eclib/include/ec_object.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 108 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 102 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 52 - ((51 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
52
normal! 0
lcd ~/EC/eclib/include
wincmd w
argglobal
if bufexists('~/EC/eclib/src/ec_object.c') | buffer ~/EC/eclib/src/ec_object.c | else | edit ~/EC/eclib/src/ec_object.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/EC/eclib/src
wincmd w
exe 'vert 1resize ' . ((&columns * 108 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 102 + 105) / 211)
tabedit ~/EC/eclib/include/ec_array.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 110 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 100 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 76 - ((51 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
76
normal! 0
lcd ~/EC/eclib/include
wincmd w
argglobal
if bufexists('~/EC/eclib/src/ec_array.c') | buffer ~/EC/eclib/src/ec_array.c | else | edit ~/EC/eclib/src/ec_array.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 020|
lcd ~/EC/eclib/src
wincmd w
exe 'vert 1resize ' . ((&columns * 110 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 100 + 105) / 211)
tabedit ~/EC/eclib/include/ec_list.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 112 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 98 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 160 - ((51 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
160
normal! 0
lcd ~/EC/eclib/include
wincmd w
argglobal
if bufexists('~/EC/eclib/src/ec_list.c') | buffer ~/EC/eclib/src/ec_list.c | else | edit ~/EC/eclib/src/ec_list.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/EC/eclib/src
wincmd w
exe 'vert 1resize ' . ((&columns * 112 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 98 + 105) / 211)
tabedit ~/EC/eclib/include/ec_garbage.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 102 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 108 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 6 - ((5 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
6
normal! 0
lcd ~/EC/eclib/include
wincmd w
argglobal
if bufexists('~/EC/eclib/src/ec_garbage.c') | buffer ~/EC/eclib/src/ec_garbage.c | else | edit ~/EC/eclib/src/ec_garbage.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/EC/eclib/src
wincmd w
exe 'vert 1resize ' . ((&columns * 102 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 108 + 105) / 211)
tabedit ~/EC/eclib/include/ec_vector.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 4 - ((3 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
4
normal! 014|
lcd ~/EC/eclib/include
wincmd w
argglobal
if bufexists('~/EC/eclib/src/ec_vector.c') | buffer ~/EC/eclib/src/ec_vector.c | else | edit ~/EC/eclib/src/ec_vector.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 3 - ((2 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
3
normal! 011|
lcd ~/EC/eclib/src
wincmd w
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
tabedit ~/EC/eclib/include/ec_syntax.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 04|
lcd ~/EC/eclib/include
wincmd w
argglobal
if bufexists('~/EC/eclib/src/ec_syntax.c') | buffer ~/EC/eclib/src/ec_syntax.c | else | edit ~/EC/eclib/src/ec_syntax.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/EC/eclib/src
wincmd w
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
tabedit ~/EC/eclib/include/ec_bool.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 10 - ((9 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
10
normal! 08|
lcd ~/EC/eclib/include
wincmd w
argglobal
if bufexists('~/EC/eclib/src/ec_bool.c') | buffer ~/EC/eclib/src/ec_bool.c | else | edit ~/EC/eclib/src/ec_bool.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/EC/eclib/src
wincmd w
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
tabedit ~/EC/eclib/include/ec_string.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/EC/eclib/include
wincmd w
argglobal
if bufexists('~/EC/eclib/src/ec_string.c') | buffer ~/EC/eclib/src/ec_string.c | else | edit ~/EC/eclib/src/ec_string.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/EC/eclib/src
wincmd w
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
tabedit ~/EC/eclib/include/ec_error.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 6 - ((5 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
6
normal! 0
lcd ~/EC/eclib/include
wincmd w
argglobal
if bufexists('~/EC/eclib/src/ec_error.c') | buffer ~/EC/eclib/src/ec_error.c | else | edit ~/EC/eclib/src/ec_error.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 13 - ((12 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
13
normal! 02|
lcd ~/EC/eclib/src
wincmd w
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
tabedit ~/EC/eclib/tools/CMakeLists.txt
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 43 - ((35 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
43
normal! 02|
lcd ~/EC/eclib/tools
wincmd w
argglobal
if bufexists('~/EC/eclib/tools/setup.sh') | buffer ~/EC/eclib/tools/setup.sh | else | edit ~/EC/eclib/tools/setup.sh | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 21 - ((20 * winheight(0) + 27) / 55)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
21
normal! 0
lcd ~/EC/eclib/tools
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 105 + 105) / 211)
exe 'vert 2resize ' . ((&columns * 105 + 105) / 211)
tabnext 12
set stal=1
if exists('s:wipebuf')
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=filmnrxoOtT
set winminheight=0 winminwidth=1
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :

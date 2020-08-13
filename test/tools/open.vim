let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +1 EC/test/src/ec_object.c
badd +11 EC/test/src/ec_array_test.c
badd +14 EC/test/src/ec_object_test.c
badd +54 EC/test/src/ec_list_test.c
badd +5 EC/test/src/ec_test.c
badd +1 EC/test/src/ec_class_test.c
badd +3 EC/test/include/ec_test.h
badd +1 EC/test/include/ec_class_test.h
badd +1 EC/test/include/ec_object_test.h
badd +1 EC/test/include/ec_array_test.h
badd +4 EC/test/include/ec_list_test.h
argglobal
silent! argdel *
set stal=2
edit EC/test/include/ec_test.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 38 + 40) / 80)
exe 'vert 2resize ' . ((&columns * 41 + 40) / 80)
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
let s:l = 3 - ((1 * winheight(0) + 10) / 21)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
3
normal! 0
lcd ~/EC/test/include
wincmd w
argglobal
if bufexists('~/EC/test/src/ec_test.c') | buffer ~/EC/test/src/ec_test.c | else | edit ~/EC/test/src/ec_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 9 - ((3 * winheight(0) + 10) / 21)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
9
normal! 0
lcd ~/EC/test/src
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 38 + 40) / 80)
exe 'vert 2resize ' . ((&columns * 41 + 40) / 80)
tabedit ~/EC/test/include/ec_class_test.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 39 + 40) / 80)
exe 'vert 2resize ' . ((&columns * 40 + 40) / 80)
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
let s:l = 4 - ((1 * winheight(0) + 10) / 21)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
4
normal! 011|
lcd ~/EC/test/include
wincmd w
argglobal
if bufexists('~/EC/test/src/ec_class_test.c') | buffer ~/EC/test/src/ec_class_test.c | else | edit ~/EC/test/src/ec_class_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 12 - ((4 * winheight(0) + 10) / 21)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
12
normal! 0
lcd ~/EC/test
wincmd w
exe 'vert 1resize ' . ((&columns * 39 + 40) / 80)
exe 'vert 2resize ' . ((&columns * 40 + 40) / 80)
tabedit ~/EC/test/include/ec_object_test.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 39 + 40) / 80)
exe 'vert 2resize ' . ((&columns * 40 + 40) / 80)
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
let s:l = 3 - ((1 * winheight(0) + 10) / 21)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
3
normal! 0
lcd ~/EC/test/include
wincmd w
argglobal
if bufexists('~/EC/test/src/ec_object_test.c') | buffer ~/EC/test/src/ec_object_test.c | else | edit ~/EC/test/src/ec_object_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 14 - ((5 * winheight(0) + 10) / 21)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
14
normal! 014|
lcd ~/EC/test
wincmd w
exe 'vert 1resize ' . ((&columns * 39 + 40) / 80)
exe 'vert 2resize ' . ((&columns * 40 + 40) / 80)
tabedit ~/EC/test/include/ec_array_test.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 39 + 40) / 80)
exe 'vert 2resize ' . ((&columns * 40 + 40) / 80)
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
let s:l = 3 - ((1 * winheight(0) + 10) / 21)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
3
normal! 0
lcd ~/EC/test/include
wincmd w
argglobal
if bufexists('~/EC/test/src/ec_array_test.c') | buffer ~/EC/test/src/ec_array_test.c | else | edit ~/EC/test/src/ec_array_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 11 - ((4 * winheight(0) + 10) / 21)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
11
normal! 0
lcd ~/EC/test
wincmd w
exe 'vert 1resize ' . ((&columns * 39 + 40) / 80)
exe 'vert 2resize ' . ((&columns * 40 + 40) / 80)
tabedit ~/EC/test/include/ec_list_test.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=1 winheight=1 winminwidth=1 winwidth=1
exe 'vert 1resize ' . ((&columns * 39 + 40) / 80)
exe 'vert 2resize ' . ((&columns * 40 + 40) / 80)
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
let s:l = 3 - ((1 * winheight(0) + 10) / 21)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
3
normal! 0
lcd ~/EC/test/include
wincmd w
argglobal
if bufexists('~/EC/test/src/ec_list_test.c') | buffer ~/EC/test/src/ec_list_test.c | else | edit ~/EC/test/src/ec_list_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 54 - ((19 * winheight(0) + 10) / 21)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
54
normal! 0
lcd ~/EC/test
wincmd w
exe 'vert 1resize ' . ((&columns * 39 + 40) / 80)
exe 'vert 2resize ' . ((&columns * 40 + 40) / 80)
tabnext 1
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

let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
argglobal
%argdel
set stal=2
tabnew
tabnew
tabnew
tabnew
tabnew
tabnew
tabrewind
edit ec/test/include/ec_test.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
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
let s:l = 1 - ((0 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 018|
lcd ~/ec/test/include
wincmd w
argglobal
if bufexists("~/ec/test/src/ec_test.c") | buffer ~/ec/test/src/ec_test.c | else | edit ~/ec/test/src/ec_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 51 - ((35 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
51
normal! 022|
lcd ~/ec/test/src
wincmd w
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
tabnext
edit ~/ec/test/include/ec_type_test.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 100 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 102 + 101) / 203)
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
let s:l = 1 - ((0 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/ec/test/include
wincmd w
argglobal
if bufexists("~/ec/test/src/ec_type_test.c") | buffer ~/ec/test/src/ec_type_test.c | else | edit ~/ec/test/src/ec_type_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 14 - ((13 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
14
normal! 037|
lcd ~/ec/test/src
wincmd w
exe 'vert 1resize ' . ((&columns * 100 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 102 + 101) / 203)
tabnext
edit ~/ec/test/include/ec_variable_test.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 100 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 102 + 101) / 203)
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
let s:l = 9 - ((8 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
9
normal! 020|
lcd ~/ec/test/include
wincmd w
argglobal
if bufexists("~/ec/test/src/ec_variable_test.c") | buffer ~/ec/test/src/ec_variable_test.c | else | edit ~/ec/test/src/ec_variable_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 20 - ((19 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
20
normal! 0
lcd ~/ec/test/src
wincmd w
exe 'vert 1resize ' . ((&columns * 100 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 102 + 101) / 203)
tabnext
edit ~/ec/test/include/ec_array_test.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 100 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 102 + 101) / 203)
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
let s:l = 1 - ((0 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/ec/test/include
wincmd w
argglobal
if bufexists("~/ec/test/src/ec_array_test.c") | buffer ~/ec/test/src/ec_array_test.c | else | edit ~/ec/test/src/ec_array_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/ec/test/src
wincmd w
exe 'vert 1resize ' . ((&columns * 100 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 102 + 101) / 203)
tabnext
edit ~/ec/test/include/ec_list_test.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 100 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 102 + 101) / 203)
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
let s:l = 1 - ((0 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/ec/test/include
wincmd w
argglobal
if bufexists("~/ec/test/src/ec_list_test.c") | buffer ~/ec/test/src/ec_list_test.c | else | edit ~/ec/test/src/ec_list_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/ec/test
wincmd w
exe 'vert 1resize ' . ((&columns * 100 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 102 + 101) / 203)
tabnext
edit ~/ec/test/include/ec_queue_test.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
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
let s:l = 1 - ((0 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/ec/test/include
wincmd w
argglobal
if bufexists("~/ec/test/src/ec_queue_test.c") | buffer ~/ec/test/src/ec_queue_test.c | else | edit ~/ec/test/src/ec_queue_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/ec/test/src
wincmd w
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
tabnext
edit ~/ec/test/include/student.h
set splitbelow splitright
wincmd _ | wincmd |
vsplit
1wincmd h
wincmd w
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
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
let s:l = 1 - ((0 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/ec/test/include
wincmd w
argglobal
if bufexists("~/ec/test/src/student.c") | buffer ~/ec/test/src/student.c | else | edit ~/ec/test/src/student.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 1 - ((0 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
lcd ~/ec/test/src
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
tabnext 7
set stal=1
badd +1 ~/ec/test/include/ec_test.h
badd +1 ~/ec/test/include/ec_type_test.h
badd +1 ~/ec/test/include/ec_variable_test.h
badd +3 ~/ec/test/include/ec_array_test.h
badd +1 ~/ec/test/include/ec_list_test.h
badd +4 ~/ec/test/include/ec_queue_test.h
badd +49 ~/ec/test/src/ec_test.c
badd +1 ~/ec/test/src/ec_type_test.c
badd +0 ~/ec/test/src/ec_variable_test.c
badd +11 ~/ec/test/src/ec_array_test.c
badd +54 ~/ec/test/src/ec_list_test.c
badd +1 ~/ec/test/src/ec_queue_test.c
badd +9 ~/ec/test/include/ec_class_test.h
badd +9 ~/ec/test/include/ec_object_test.h
badd +16 ~/ec/test/src/ec_class_test.c
badd +14 ~/ec/test/src/ec_object_test.c
badd +1 ~/ec/test/src/ec_object.c
badd +1 ~/ec/test/include/student.h
badd +1 ~/ec/test/src/student.c
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
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

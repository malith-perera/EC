let SessionLoad = 1
if &cp | set nocp | endif
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
silent tabonly
cd ~/ExtendedC/lib/test
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
edit include/ec_test.h
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
let s:l = 15 - ((14 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
15
normal! 016|
lcd ~/ExtendedC/lib/test/include
wincmd w
argglobal
if bufexists("~/ExtendedC/lib/test/src/ec_test.c") | buffer ~/ExtendedC/lib/test/src/ec_test.c | else | edit ~/ExtendedC/lib/test/src/ec_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 69 - ((42 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
69
normal! 05|
lcd ~/ExtendedC/lib/test/src
wincmd w
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
tabnext
edit ~/ExtendedC/lib/test/include/ec_var_test.h
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
let s:l = 10 - ((9 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
10
normal! 0
lcd ~/ExtendedC/lib/test/include
wincmd w
argglobal
if bufexists("~/ExtendedC/lib/test/src/ec_ref_var_test.c") | buffer ~/ExtendedC/lib/test/src/ec_ref_var_test.c | else | edit ~/ExtendedC/lib/test/src/ec_ref_var_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 73 - ((3 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
73
normal! 03|
lcd ~/ExtendedC/lib/test/src
wincmd w
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
tabnext
edit ~/ExtendedC/lib/test/include/ec_ref_array_test.h
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
let s:l = 8 - ((7 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
8
normal! 0
lcd ~/ExtendedC/lib/test/include
wincmd w
argglobal
if bufexists("~/ExtendedC/lib/test/src/ec_ref_array_test.c") | buffer ~/ExtendedC/lib/test/src/ec_ref_array_test.c | else | edit ~/ExtendedC/lib/test/src/ec_ref_array_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 450 - ((25 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
450
normal! 0
lcd ~/ExtendedC/lib/test/src
wincmd w
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
tabnext
edit ~/ExtendedC/lib/test/include/ec_ref_list_test.h
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
let s:l = 8 - ((7 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
8
normal! 0
lcd ~/ExtendedC/lib/test/include
wincmd w
argglobal
if bufexists("~/ExtendedC/lib/test/src/ec_ref_list_test.c") | buffer ~/ExtendedC/lib/test/src/ec_ref_list_test.c | else | edit ~/ExtendedC/lib/test/src/ec_ref_list_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 341 - ((45 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
341
normal! 03|
lcd ~/ExtendedC/lib/test/src
wincmd w
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
tabnext
edit ~/ExtendedC/lib/test/include/ec_ref_queue_test.h
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
let s:l = 8 - ((7 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
8
normal! 0
lcd ~/ExtendedC/lib/test/include
wincmd w
argglobal
if bufexists("~/ExtendedC/lib/test/src/ec_ref_queue_test.c") | buffer ~/ExtendedC/lib/test/src/ec_ref_queue_test.c | else | edit ~/ExtendedC/lib/test/src/ec_ref_queue_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 238 - ((48 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
238
normal! 05|
lcd ~/ExtendedC/lib/test/src
wincmd w
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
tabnext
edit ~/ExtendedC/lib/test/include/ec_ref_stack_test.h
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
let s:l = 8 - ((7 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
8
normal! 0
lcd ~/ExtendedC/lib/test/include
wincmd w
argglobal
if bufexists("~/ExtendedC/lib/test/src/ec_ref_stack_test.c") | buffer ~/ExtendedC/lib/test/src/ec_ref_stack_test.c | else | edit ~/ExtendedC/lib/test/src/ec_ref_stack_test.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 208 - ((51 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
208
normal! 02|
lcd ~/ExtendedC/lib/test/src
wincmd w
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
tabnext
edit ~/ExtendedC/lib/test/include/student.h
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
let s:l = 16 - ((15 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
16
normal! 07|
lcd ~/ExtendedC/lib/test/include
wincmd w
argglobal
if bufexists("~/ExtendedC/lib/test/src/student.c") | buffer ~/ExtendedC/lib/test/src/student.c | else | edit ~/ExtendedC/lib/test/src/student.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr={{{,}}}
setlocal fdi=#
setlocal fdl=0
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 4 - ((3 * winheight(0) + 26) / 52)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
4
normal! 07|
lcd ~/ExtendedC/lib/test/src
wincmd w
2wincmd w
exe 'vert 1resize ' . ((&columns * 101 + 101) / 203)
exe 'vert 2resize ' . ((&columns * 101 + 101) / 203)
tabnext 7
set stal=1
badd +8 ~/ExtendedC/lib/test/include/ec_var_test.h
badd +1 ~/ExtendedC/lib/test/src/ec_ref_var_test.c
badd +1 ~/ExtendedC/lib/test/include/ec_ref_array_test.h
badd +1 ~/ExtendedC/lib/test/src/ec_ref_array_test.c
badd +1 ~/ExtendedC/lib/test/include/ec_ref_list_test.h
badd +1 ~/ExtendedC/lib/test/src/ec_ref_list_test.c
badd +1 ~/ExtendedC/lib/test/include/ec_ref_queue_test.h
badd +1 ~/ExtendedC/lib/test/src/ec_ref_queue_test.c
badd +1 ~/ExtendedC/lib/test/include/ec_ref_stack_test.h
badd +0 ~/ExtendedC/lib/test/src/ec_ref_stack_test.c
badd +69 ~/ExtendedC/lib/test/src/ec_test.c
badd +0 ~/ExtendedC/lib/test/include/ec_test.h
badd +16 ~/ExtendedC/lib/test/include/student.h
badd +0 ~/ExtendedC/lib/test/src/student.c
if exists('s:wipebuf') && len(win_findbuf(s:wipebuf)) == 0
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 shortmess=SfilmnrxoOtT
set winminheight=0 winminwidth=1
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :

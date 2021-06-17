# Cracking the code interview. 6th edition

## Running `<program>`

```bash
g++ <program>.cpp -o <program>
./program
```

Cool oneliner to compile, run, and cleanup (for VIM):

```viml
autocmd filetype cpp nnoremap <F4> :w <bar> exec '!g++ '.shellescape('%').' -o '.shellescape('%:r').' && ./'.shellescape('%:r') '&& rm -rf '.shellescape('%:r')<CR>
```

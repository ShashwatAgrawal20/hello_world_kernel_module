## shitty hello world kernel module

**Make sure you have your clangd properly setup**
- `~/.config/clangd/config.yaml`
This will make sure that the LSP has access to the required headers and the `compiled_commands.json` won't contain the flags listed in the `Remove` section.
```yaml
CompileFlags:
    Add: [-I/usr/src/linux-lts/include/]
    Remove: [   -mpreferred-stack-boundary=*,
                -mindirect-branch*,
                -fno-allow-store-data-races,
                -fno-var-tracking-assignments,
                -fconserve-stack,
                -mrecord-mcount,
            ]
```

---
Now we're ready to build our kernel module.

```bash
make
```

Once it's done building you've to generate the `compiled_commands.json`(In order to generate this file have to compile the module/kernel atleast once, it doesn't matter even if that's a compilation of empty C file.)
```bash
python gen_compiled.compiled_commands.py
```

The module should be ready btw, we if you aren't coding you don't probably need to generate the `compiled_commands.json` but we did that anyways.

---

**It's time to LOAD/UNLOAD the kernel.**

1. You can watch the kernel activity using(run this in a seperate terminal)
```bash
sudo dmesg --follow
```
2. Loading the module
```bash
sudo insmod deeznuts.ko
```
You'll see some text pop-up on your dmesg screen.

3. Unloading the module
```bash
sudo rmmod deeznuts.ko
```
You'll again see some text pop-up on your dmesg screen.

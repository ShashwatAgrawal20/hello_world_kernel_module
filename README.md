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
bear -- make
```
This will also generate the `compiled_commands.json` file, which is required for our LSP to work properly with the kernel, and other required compilation flags and stuff.

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

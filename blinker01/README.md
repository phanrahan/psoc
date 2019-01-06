Attach to nit
System USB
lsusb

Try connecting with prog

Try connecting with openocd

openocd programmer for the kitprog
http://www.psoctools.org/psoc5lp-tools.html

openocd --verbose -c "interface kitprog; kitprog_init_acquire_psoc" -f target/psoc5lp.cfg

openocd -c "interface kitprog; kitprog_init_acquire_psoc" -f target/psoc5lp.cfg -c "init; halt; psoc5lp mass_erase 0; program mecrisp-stellaris-cy8c5888.bin 0x0 verify reset exit"

Target device: psoc5lp cy8c5888
Button: P2.2
LED: P2.1

mecript forth runs on the cypress psoc

reverse engeineering the logic fabric
https://hub.darcs.net/pointfree/psoc-tabular

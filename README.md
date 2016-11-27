# Buck Adaptors

This repository contains a adaptors to various libraries written in C++ for
portability.  Folders in this repository are submodule backed and install any
of the adaptors included in this repository with the following

```shell
git submodule add <remote> <name of library>
```
And then add the relevant repository to the `.buckconfig` for your project

```shell
[repositories]
    <name of library> = <path of submodule>
```

### Motivation

Compilation in C++ with external libraries has been a massive pain in the past
because it invariably involves some sort of install process with a complicated
bootstrap shell script that dumps unwanted things into your file system, and
often require sudo access.

Buck in addition to being a cross language build platform, can also solve the
problem of installing external libraries by virtue of its modularized
structure of compile files.

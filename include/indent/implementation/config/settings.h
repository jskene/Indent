/**
 * @file
 * Conveyed compile-time settings for Floods
 *
 * # Conveyed settings
 *
 * User code that uses Floods needs to use the same set of compile time
 * settings for Floods that Floods was compiled with.  The deployer of Floods
 * on a given platform should add the settings to this file.  Settings that
 * are not given here will be guessed, and should not be overridden by user
 * settings *unless* it is known for sure that Floods was compiled with a
 * different set of settings (e.g. because a standalone deployment of Floods
 * and the user code are being compiled together using a common build system).
 */

#pragma once

// This header must include output streams, string and string streams

#define INDENT_USE_STD
//#define INDENT_USE_FLOODS

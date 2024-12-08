These keymaps are using keymap_german_mac_iso.
Symbols are 'translated', if a linux/windows host is detected.

# Base Layers
First and last column keys on base layers for 6x3 keyboards,
(X) is the corresponding key from the currently active base layer:
```
 A/BSp│                         │A/(X)
 ─────┼─                       ─┼─────
 C/Esc│   (...other keys...)    │C/(X)
 ─────┼─                       ─┼─────
 G/App│                         │G/Ent
```

All base layers share the same thumb cluster:
(If the keyboard only has 2 keys on one side, the outermost key (marked with *) is missing)
```
           *                     *
          Esc│Ent│Tab│ │Bsp│Spc│Del
          ───┴───┴LOW┘ └RSE┴───┴───
```

## QWERTY (german adaption)
```
 q │ w │ e │ r │ t         z │ u │ i │ o │ p │(ü)
───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 a │ s │ d │ f │ g         h │ j │ k │ l │ ö │(ä)
─Σ─┼───┼───┼───┼───       ───┼───┼───┼───┼─Σ─ ───
 y │ x │ c │ v │ b         n │ m │ , │ . │ ß │
─M─┴───┴───┴───┴───       ───┴───┴───┴───┴─M─
```

## BONE
```
 j │ d │ u │ a │ x         p │ h │ l │ m │ w │(ß)
───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 c │ t │ i │ e │ o         b │ n │ r │ s │ g │(q)
─Σ─┼───┼───┼───┼───       ───┼───┼───┼───┼─Σ─ ───
 f │ v │ ü │ ä │ ö         y │ z │ , │ . │ k │
─M─┴───┴───┴───┴───       ───┴───┴───┴───┴─M─
```

## Colemak (Mod DH, german adaption)
```
 q │ w │ f │ p │ b         j │ l │ u │ y │ ö │(ü)
───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ───
 a │ r │ s │ t │ g         m │ n │ e │ i │ o │(ä)
─Σ─┼───┼───┼───┼───       ───┼───┼───┼───┼─Σ─ ───
 z │ x │ c │ d │ v         k │ h │ , │ . │ ß │
─M─┴───┴───┴───┴───       ───┴───┴───┴───┴─M─
```

# Additional Layers

## Symbols
```
 (ALT)│ @ │ _ │ [ │ ] │ ^         ! │ < │ > │ = │ & │(ALT)
 ───── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ─────
 (CTL)│ \ │ / │ { │ } │ *         ? │ ( │ ) │ - │ : │(CTL)
 ───── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ─────
 (GUI)│ # │ $ │ | │ ~ │ ´         + │ % │ " │ ' │ ; │(GUI)
                 ───┌───┬───┐ ┌───┬───┐───
                  ° │ § │ ` │ │AGr│Spc│CWT
                 ───└───┴───┘ └───┴───┘───
```
       (when dynamic tapping term is enabled, thumbs change to:)
```
                 ───┌───┬───┐ ┌───┬───┐───
                 PTT│ § │TT+│ │TT-│Spc│CWT
                 ───└───┴───┘ └───┴───┘───
```

## Lower (Function keys and numbers)
```
 (ALT)│F1 │F2 │F3 │F4 │ £         / │ 7 │ 8 │ 9 │ - │(ALT)
 ───── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ─────
 (CTL)│F5 │F6 │F7 │F8 │ €         + │ 4 │ 5 │ 6 │ . │(CTL)
 ───── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ─────
 (GUI)│F9 │F10│F11│F12│ ¢         0 │ 1 │ 2 │ 3 │ , │(GUI)
                 ───┌───┬───┐ ┌───┬───┐───
                  $ │Sft│(v)│ │Bsp│Spc│App
                 ───└───┴───┘ └ATT┴───┘───
```

## Raise (Navigation and control keys)
(the home row modifiers on the right are sticky)
```
 (ALT)│PUp│BSp│ ↑ │Del│Ins       Prv│Stp│Ply│Nxt│Ejt│(ALT)
 ───── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ─────
 (CTL)│Hme│ ← │ ↓ │ → │End     * Meh│Sft│Ctl│Alt│Gui│(CTL)
 ───── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ─────
 (GUI)│Esc│Cut│Cpy│Pst│PDn       PSc│CWT│Pse│AGr│SLk│(GUI)
                 ───┌───┬───┐ ┌───┬───┐───
                 Prv│V -│V ×│ │(v)│V +│Nxt
                 ───└───┴ATT┘ └───┴───┘───
```

## Pointer (Mouse)
(only if mouse keys are enabled)
* GSC: GUI+Shift+Click
* CSC: CTL+Shift+Click
```
 (ALT)│vMv│<M<│Ms↑│>M>│             │GSC│CSC│   │   │(ALT)
 ───── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ─────
 (CTL)│Bt4│Ms←│Ms↓│Ms→│Bt5       Meh│Sft│Ctl│Alt│Gui│(CTL)
 ───── ───┼───┼───┼───┼───       ───┼───┼───┼───┼─── ─────
 (GUI)│Tb←│Cut│Cpy│Pst│^M^       Slo│Med│Fst│AGr│Tb→│(GUI)
                 ───┌───┬───┐ ┌───┬───┐───
                 GSC│Bt1│Bt2│ │Gui│Bt3│CSC
                 ───└───┴───┘ └───┴───┘───
```

## Attic (Adjustments and missing stuff)
```
 (ALT)│QBt│ECl│LAs│LAr│APP        ¡ │ ‹ │ « │ » │ › │(§)
 ───── ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 (CTL)│LyG│Ly←│Ly→│BsL│MDX        ¿ │ • │ ‚ │ ‘ │ ’ │(…)
 ───── ───┼───┼───┼───┼───       ───┼───┼───┼───┼───
 (GUI)│RGB│R_S│R_H│R_V│R_M       n-–│m-—│ „ │ “ │ ”
                 ───┌───┬───┐ ┌───┬───┐───
                 LSf│Br-│(v)│ │(v)│Br+│RSf
                 ───└───┴───┘ └───┴───┘───
```

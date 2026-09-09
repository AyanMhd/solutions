# Binary String Insertion Observation

| Pair | Insert `0` | Insert `1` |
|---|---|---|
| `00` | `00 + 1` | `01 + 1`, `10 + 1`, `00 - 1` |
| `01` | `00 + 1` | `11 + 1` |
| `10` | `00 + 1` | `11 + 1` |
| `11` | `01 + 1`, `10 + 1`, `11 - 1` | `11 + 1` |

For a **cyclic binary string**:

```text
cnt01 = cnt10
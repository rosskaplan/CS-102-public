import re
import json
import subprocess

def run(match):
    string = match.group(1)
    opts = json.loads(string)
    path = opts['code']
    #inp = bytes(opts.get('input'), encoding='utf8')
    inp = opts.get('input')
    if inp:
        inp = bytes(inp, encoding='utf8')
    with open(path) as f:
        content = f.read()
    proc = subprocess.run(['python3', path], capture_output=True,
                          input=inp)
    printed = b''
    if proc.stdout:
        printed += proc.stdout
    if proc.stderr:
        printed += proc.stderr

    printed = printed.decode('utf8')
    return f'```python\n{content}```\n```\n{printed}```'

with open('raw.md') as f, open('README.md', 'w') as g:
    content = f.read()
    content = re.sub(
        '```snippet(.*?)```',
        string=content,
        repl=run,
        flags=re.DOTALL)
    g.write(content)

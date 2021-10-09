#! /usr/bin/env node
import fetch from "node-fetch";
import open from "open";
import yargs from "yargs";

// parse env args
const { argv } = yargs(process.argv);

// init fetch to reddit api
const res = await fetch("https://reddit.com/.json");
const data = await res.json();
const children = data.data.children;
const randomPost = children[Math.floor(Math.random() * children.length)];

// get radom post from reddit api response of all posts on front page
const link = `https://reddit.com${randomPost.data.permalink}`;

// log if --print flag is passed
if (argv.print) {
  console.log(`
    Title: ${randomPost.data.title}
    Link: ${link}
    `);
}
// if --help flag is passed print help message
else if (argv.help) {
  console.log(`
  Reddit CLI v1.0.0
  - from Pranav Yadav <https://github.com/pranav-yadav/>

  USAGE: reddit [options]
  EXAMPLE:
         reddit                : Opens random post on reddit in new browser window
         reddit --help
         reddit --print
  
  OPTIONS:
    --help:      Prints this Help Message on console
    --print:     Prints \`Title\` and \`Link\` of random post from Reddit
    --version:   Prints the current Rddit CLI version
  `);
}
// if --version flag is passed print the version
else if (argv.version) {
  console.log(`
  Reddit CLI \`v1.0.0\`
  - from Pranav Yadav <https://github.com/pranav-yadav/>
  `);
}
// else open in browser
else {
  await open(link); //{ app: { name: "google chrome",  arguments: ['--incognito']} }
}

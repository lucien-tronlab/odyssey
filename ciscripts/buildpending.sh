#!/bin/bash
curl --silent -XPOST -H "Authorization: token $GITHUB_SECRET" https://api.github.com/repos/odyssey/odyssey/statuses/$(git rev-parse HEAD) -d "{
  \"state\": \"pending\",
  \"target_url\": \"${BUILD_URL}\",
  \"description\": \"The build is now pending in jenkinsci!\",
  \"context\": \"jenkins-ci-odyssey\"
}"

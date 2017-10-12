#! /bin/bash

# 提交代码到github

get_all_dir() {
	all_files=`ls`
	for f in $all_files; do
		if [ -d $f ]; then
			echo -e "$f \c"
		fi
	done
}

clear_build() {
	all_dir=$(get_all_dir)
	for d in $all_dir; do
		cd $d
			sh build.sh clear > /dev/null 2>&1
		cd ..
	done
}

show_status() {
	if git status | grep 'nothing to commit'; then
		return 1
	else
		echo "Changed files: "
		git status -s -u
		return 0
	fi
}

commit() {
	git add *
	git commit -m "commit"

	echo "Committing ..."
	git push origin master
}

main() {
	clear_build

	if ! show_status; then
		return 0
	fi

	echo -e "--------------------------\nIs it ok [y/n]: \c"
	read answer

	if [ "$answer" == "y" ]; then
		commit
	fi
}

main

exit 0

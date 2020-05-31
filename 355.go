package main

type Twitter struct {
	users []*User
	ts int
}

type User struct {
	followeeIds map[int]bool
	tweets    []*int
	feed        []*int
}

type Tweet {
	tweetId int
	ts int
}

/** Initialize your data structure here. */
func Constructor() Twitter {
	return Twitter{ts: 0}
}

func (this *Twitter) addUser(userId int) *User {
	for userId > len(this.users) {
		this.users = append(this.users, &User{followeeIds: make(map[int]bool)})
	}
	return this.users[userId-1]
}

/** Compose a new tweet. */
func (this *Twitter) PostTweet(userId int, tweetId int) {
	user := this.addUser(userId)
	tweet := &Tweet{tweetId, this.ts}
	user.tweets = append(user.tweets, tweet)
	if len(user.tweets) > 10 {
		user.tweets = user.tweets[1:]
	}
	for uid, _ := range user.followeeIds {
		u := this.users[uid]
		u.feed = append(u.feed, tweet)
		if len(u.feed) > 10 {
			u.feed = u.feed[1:]
		}
	}
	ts++
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
func (this *Twitter) GetNewsFeed(userId int) []int {
	user := this.users[userId-1]
	return user.feed
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
func (this *Twitter) Follow(followerId int, followeeId int) {
	user := this.users[followerId-1]
	user.followeeIds[followeeId] = true
	followee := this.users[followeeId-1]
	if len(followee.feed) < 10 || followee.feed[0] {
		u.feed = append(u.feed, &Tweet{tweetId, this.ts})
	}
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
func (this *Twitter) Unfollow(followerId int, followeeId int) {
	user := this.users[followerId-1]
	delete(user.followeeIds, followeeId)
}

/**
 * Your Twitter object will be instantiated and called as such:
 * obj := Constructor();
 * obj.PostTweet(userId,tweetId);
 * param_2 := obj.GetNewsFeed(userId);
 * obj.Follow(followerId,followeeId);
 * obj.Unfollow(followerId,followeeId);
 */
